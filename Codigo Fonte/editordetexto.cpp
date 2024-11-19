#include "editordetexto.h"
#include "ui_editordetexto.h"
#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QTextCharFormat>
#include <QFileInfo>
#include <QInputDialog>
#include <QTextCursor>


EditorDeTexto::EditorDeTexto(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EditorDeTexto)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

    connect(ui->textEdit, &QTextEdit::cursorPositionChanged, this, &EditorDeTexto::clearHighlight);
}


class SyntaxHighlighter : public QSyntaxHighlighter
{
public:
    SyntaxHighlighter(QTextDocument *parent, const QString &language)
        : QSyntaxHighlighter(parent), currentLanguage(language)
    {
        if (language == "cpp") {
            setupCppRules();
        } else if (language == "py") {
            setupPythonRules();
        }
    }

protected:
    void highlightBlock(const QString &text) override
    {
        for (const HighlightingRule &rule : qAsConst(highlightingRules)) {
            QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
            while (matchIterator.hasNext()) {
                QRegularExpressionMatch match = matchIterator.next();
                setFormat(match.capturedStart(), match.capturedLength(), rule.format);
            }
        }
    }

private:
    struct HighlightingRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };

    QVector<HighlightingRule> highlightingRules;
    QString currentLanguage;

    void setupCppRules()
    {
        HighlightingRule rule;
        // 1. Palavras-chave - azul
        QTextCharFormat keywordFormat;
        keywordFormat.setForeground(Qt::darkCyan);
        QStringList keywordPatterns = { "\\bif\\b", "\\belse\\b", "\\bfor\\b", "\\bwhile\\b", "\\breturn\\b"};
        for (const QString &pattern : keywordPatterns) {
            rule.pattern = QRegularExpression(pattern);
            rule.format = keywordFormat;
            highlightingRules.append(rule);
        }

        // 2. Diretivas do pré-processador (como #include)
        QTextCharFormat preprocessorFormat;
        preprocessorFormat.setForeground(Qt::cyan);
        rule.pattern = QRegularExpression("^#\\s*\\binclude\\b");  // Regex para capturar o '#' no início seguido de 'include'
        rule.format = preprocessorFormat;
        highlightingRules.append(rule);

        // 2. Tipos - verde escuro
        QTextCharFormat typeFormat;
        typeFormat.setForeground(Qt::darkGreen);
        QStringList typePatterns = { "\\bint\\b", "\\bfloat\\b", "\\bdouble\\b", "\\bchar\\b", "\\bvoid\\b" };
        for (const QString &pattern : typePatterns) {
            rule.pattern = QRegularExpression(pattern);
            rule.format = typeFormat;
            highlightingRules.append(rule);
        }

        // 3. Funções - roxo
        QTextCharFormat functionFormat;
        functionFormat.setForeground(Qt::magenta);
        rule.pattern = QRegularExpression("\\b[A-Za-z0-9_]+(?=\\()");
        rule.format = functionFormat;
        highlightingRules.append(rule);

        // 4. Strings - marrom
        QTextCharFormat stringFormat;
        stringFormat.setForeground(Qt::red);
        rule.pattern = QRegularExpression("\".*\"");
        rule.format = stringFormat;
        highlightingRules.append(rule);

        // 5. Comentários de linha - cinza claro
        QTextCharFormat singleLineCommentFormat;
        singleLineCommentFormat.setForeground(Qt::gray);
        rule.pattern = QRegularExpression("//[^\n]*");
        rule.format = singleLineCommentFormat;
        highlightingRules.append(rule);

        // 6. Comentários de bloco - cinza claro
        QTextCharFormat multiLineCommentFormat;
        multiLineCommentFormat.setForeground(Qt::gray);
        rule.pattern = QRegularExpression("/\\*.*?\\*/");
        rule.format = multiLineCommentFormat;
        highlightingRules.append(rule);

        // 7. Números - laranja
        QTextCharFormat numberFormat;
        numberFormat.setForeground(Qt::darkYellow);
        rule.pattern = QRegularExpression("\\b\\d+\\b");
        rule.format = numberFormat;
        highlightingRules.append(rule);
    }

    void setupPythonRules()
    {
        HighlightingRule rule;
        QTextCharFormat keywordFormat;
        keywordFormat.setForeground(Qt::darkYellow);
        QStringList keywordPatterns = { "\\bdef\\b", "\\bclass\\b", "\\bimport\\b", "\\bself\\b" };
        for (const QString &pattern : keywordPatterns) {
            rule.pattern = QRegularExpression(pattern);
            rule.format = keywordFormat;
            highlightingRules.append(rule);
        }
    }
};



EditorDeTexto::~EditorDeTexto()
{
    delete ui;
}

void EditorDeTexto::on_actionNovo_triggered()
{
    localfilename = "";
    ui->textEdit->clear();
    ui->textEdit->setFocus();

}


void EditorDeTexto::on_actionAbrir_triggered()
{
    QString filename = QFileDialog::getOpenFileName( this , "Abrir", QDir::homePath(), all_files);
    QFile file( filename );
    localfilename = filename;

    if( file.exists() ){
        if( !file.open( QFile::ReadOnly | QFile::Text) ){
            QMessageBox::warning( this, "Erro ao abri o arquivo", "Arquivo não pode ser aberto" );
            return;
        }

        QTextStream enter_file( &file );
        QString text = enter_file.readAll();
        ui->textEdit->setText( text);


        QString extension = QFileInfo(filename).suffix();
        QString language;

        if (extension == "cpp" || extension == "h" || extension == "c") language = "cpp";
        else if (extension == "py") language = "py";
        else language = "plaintext";

        new SyntaxHighlighter(ui->textEdit->document(), language); // Aplica o realce com base na linguagem


    }
    file.close();
}


void EditorDeTexto::on_actionSalvar_Como_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this , "Salvar Como", QDir::homePath(), all_files);
    localfilename = filename;

    if( localfilename == ""){
        return;
    }

    QFile file( filename );


    if( !file.open( QFile::WriteOnly | QFile::Text) ){
        if( file.exists() ){
            QMessageBox::warning( this, "Erro ao salvar o arquivo", "Arquivo não pode ser salvo" );
        }
        return;
    }
    QTextStream out_file( &file );
    QString text = ui->textEdit->toPlainText();
    out_file << text << '\n';

    file.flush();
    file.close();

    // **Atualização para identificar a extensão e aplicar o realce de sintaxe**
    QString extension = QFileInfo(filename).suffix();
    QString language;

    if (extension == "cpp" || extension == "h" || extension == "c") language = "cpp";
    else if (extension == "py") language = "py";
    else language = "plaintext";

    new SyntaxHighlighter(ui->textEdit->document(), language);  // Reaplica o realce de sintaxe
}


void EditorDeTexto::on_actionSalvar_triggered()
{

    QFile file( localfilename );

    if(file.exists()){
        if( !file.open( QFile::WriteOnly | QFile::Text) ){
            QMessageBox::warning( this, "Erro", "Arquivo não pode ser salvo");
            return;
        }
        QTextStream out_file( &file );
        QString text = ui->textEdit->toPlainText();
        out_file << text << '\n';

        file.flush();
        file.close();
    }else{
        on_actionSalvar_Como_triggered();
    }



}


void EditorDeTexto::on_actionSair_triggered()
{
    close();
}


void EditorDeTexto::on_actionCopiar_triggered()
{
    ui->textEdit->copy();
}


void EditorDeTexto::on_actionColar_triggered()
{
    ui->textEdit->paste();
}


void EditorDeTexto::on_actionRecortar_triggered()
{
    ui->textEdit->cut();
}


void EditorDeTexto::on_actionRefazer_triggered()
{
    ui->textEdit->redo();
}


void EditorDeTexto::on_actionDesfazer_triggered()
{
    ui->textEdit->undo();
}


void EditorDeTexto::on_actionCor_triggered()
{
    QColor color = QColorDialog::getColor( Qt::black, this, "Escolha uma cor" );
    if( color.isValid()){
        ui->textEdit->setTextColor( color );
    }
}


void EditorDeTexto::on_actionBackgroud_triggered()
{
    QColor color = QColorDialog::getColor( Qt::black, this, "Escolha uma cor" );
    if( color.isValid()){
        ui->textEdit->setTextBackgroundColor( color );
    }
}


void EditorDeTexto::on_actionFonte_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if( ok ){
        ui->textEdit->setFont( font );
    }else{
        return;
    }
}


void EditorDeTexto::on_actionSobre_esse_programa_triggered()
{
    // Cria a caixa de mensagem
    QMessageBox aboutBox;
    aboutBox.setWindowTitle("Editor de Textos CodeWriter");
    aboutBox.setIcon(QMessageBox::NoIcon);

    // Define o texto formatado com estilos de HTML
    QString aboutText = R"(
        <div align='center' style='font-family: Arial, sans-serif;'>
            <h2 style='color: #2E86C1;'>Editor de Textos CodeWriter</h2>
            <p style='font-size: 14px;'><b>Desenvolvido por</b> <span style='color: #117A65;'>Abraão Rodrigues</span></p>
            <p style='font-size: 13px;'>
                <a href='https://abrportifolio.com/' style='color: #2980B9; text-decoration: none;'><b>Portfólio  |</b></a>
                &emsp;&emsp;&emsp;&emsp; <!-- Espaço equivalente a uma tabulação -->
                <a href='https://github.com/AbrCs7' style='color: #2980B9; text-decoration: none;'><b>  | GitHub</b></a>
            </p>
            <p style='font-size: 14px;'><b>Saiba mais sobre a </b> <span style='color: #8E44AD;'>Plume Design</span></p>
            <p style='font-size: 13px;'>
                <a href='https://plumedesign.online/' style='color: #2980B9; text-decoration: none;'><b>Acesse</b></a>
            </p>
            <hr style='border: none; height: 1px; background-color: #BDC3C7;'>
            <p style='font-size: 12px; color: #7F8C8D;'>© 2024 Plume Design. Todos os direitos reservados.</p>
        </div>
    )";

    // Configurações da caixa de mensagem
    aboutBox.setTextFormat(Qt::RichText); // Permite HTML para formatar o texto
    aboutBox.setText(aboutText);          // Define o texto formatado
    aboutBox.setStandardButtons(QMessageBox::Ok); // Botão para fechar

    // Exibe a caixa de mensagem
    aboutBox.exec();
}


void EditorDeTexto::on_actionImprimir_triggered()
{
    QPrinter printer;
    QPrintDialog dialog_printer;

    if( dialog_printer.exec() == QDialog::Rejected ){
        return;
    }
    ui->textEdit->print( &printer );
}




void EditorDeTexto::clearAllHighlights()
{
    // Limpa todos os destaques no documento
    QTextCursor cursor(ui->textEdit->document());
    QTextCharFormat clearFormat;
    clearFormat.setBackground(Qt::transparent);

    while (!cursor.isNull() && !cursor.atEnd()) {
        cursor = ui->textEdit->document()->find(searchText, cursor);
        if (!cursor.isNull()) {
            cursor.mergeCharFormat(clearFormat); // Remove o destaque
        }
    }
}

void EditorDeTexto::on_actionPesquisar_triggered()
{
    // Solicita ao usuário o termo a ser pesquisado
    searchText = QInputDialog::getText(this, "Pesquisar", "Digite o termo a ser pesquisado:");

    if (!searchText.isEmpty()) {
        // Limpa destaques anteriores
        clearAllHighlights();

        // Realça todas as ocorrências do termo
        highlightOccurrences(searchText);

        // Inicializa o cursor para a primeira ocorrência
        QTextCursor startCursor(ui->textEdit->textCursor());
        startCursor.movePosition(QTextCursor::Start);
        currentHighlightCursor = ui->textEdit->document()->find(searchText, startCursor);

        // Aplica destaque especial à primeira ocorrência, se existir
        if (!currentHighlightCursor.isNull()) {
            currentHighlightCursor.mergeCharFormat(currentHighlightFormat);
            ui->textEdit->setTextCursor(currentHighlightCursor);
        } else {
            QMessageBox::information(this, "Nenhuma ocorrência encontrada", "O termo pesquisado não foi encontrado.");
        }
    }
}


void EditorDeTexto::on_actionAvan_ar_triggered()
{

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Erro", "Nenhuma palavra foi pesquisada.");
        return;
    }

    // Remove o destaque atual
    if (!currentHighlightCursor.isNull()) {
        currentHighlightCursor.mergeCharFormat(defaultHighlightFormat);
    }

    // Encontra a próxima ocorrência
    QTextDocument::FindFlags options = QTextDocument::FindCaseSensitively;     // Busca no sentido padrão (para frente)
    currentHighlightCursor = ui->textEdit->document()->find(searchText, currentHighlightCursor, options);

    if (!currentHighlightCursor.isNull()) {
        currentHighlightCursor.mergeCharFormat(currentHighlightFormat);
        ui->textEdit->setTextCursor(currentHighlightCursor); // Move para a nova ocorrência
    } else {
        QMessageBox::information(this, "Fim da pesquisa", "Você chegou ao fim do texto. Voltando ao início.");
        // Volta ao início
        QTextCursor startCursor(ui->textEdit->textCursor());
        startCursor.movePosition(QTextCursor::Start);
        currentHighlightCursor = ui->textEdit->document()->find(searchText, startCursor, options);
        if (!currentHighlightCursor.isNull()) {
            currentHighlightCursor.mergeCharFormat(currentHighlightFormat);
            ui->textEdit->setTextCursor(currentHighlightCursor);
        }
    }
}




void EditorDeTexto::on_actionRetroceder_triggered()
{
    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Erro", "Nenhuma palavra foi pesquisada.");
        return;
    }

    // Remove o destaque atual
    if (!currentHighlightCursor.isNull()) {
        currentHighlightCursor.mergeCharFormat(defaultHighlightFormat);
    }

    // Encontra a ocorrência anterior
    QTextDocument::FindFlags options = QTextDocument::FindBackward;
    currentHighlightCursor = ui->textEdit->document()->find(searchText, currentHighlightCursor, options);

    if (!currentHighlightCursor.isNull()) {
        currentHighlightCursor.mergeCharFormat(currentHighlightFormat);
        ui->textEdit->setTextCursor(currentHighlightCursor); // Move para a nova ocorrência
    } else {
        QMessageBox::information(this, "Início da pesquisa", "Você chegou ao início do texto. Voltando ao final.");
        // Volta ao final
        QTextCursor endCursor(ui->textEdit->textCursor());
        endCursor.movePosition(QTextCursor::End);
        currentHighlightCursor = ui->textEdit->document()->find(searchText, endCursor, options);
        if (!currentHighlightCursor.isNull()) {
            currentHighlightCursor.mergeCharFormat(currentHighlightFormat);
            ui->textEdit->setTextCursor(currentHighlightCursor);
        }
    }
}


void EditorDeTexto::highlightOccurrences(const QString &text)
{
    QTextCursor cursor(ui->textEdit->document());
    QTextCharFormat format;
    format.setBackground(Qt::yellow); // Define cor de fundo para o destaque padrão

    while (!cursor.isNull() && !cursor.atEnd()) {
        cursor = ui->textEdit->document()->find(text, cursor);
        if (!cursor.isNull()) {
            cursor.mergeCharFormat(format); // Aplica o destaque
        }
    }
}



void EditorDeTexto::clearHighlight()
{
    QTextCursor cursor(ui->textEdit->document());
    QTextCharFormat clearFormat;
    clearFormat.setBackground(Qt::transparent); // Remove o fundo amarelo

    while (!cursor.isNull() && !cursor.atEnd()) {
        cursor = ui->textEdit->document()->find(searchText, cursor);
        if (!cursor.isNull()) {
            cursor.mergeCharFormat(clearFormat); // Remove o destaque
        }
    }
}




void EditorDeTexto::on_actionEnumerar_Linhas_triggered()
{

}

