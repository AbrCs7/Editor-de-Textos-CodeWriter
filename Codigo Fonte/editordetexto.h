#ifndef EDITORDETEXTO_H
#define EDITORDETEXTO_H

#include "qtextcursor.h"
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>
#include <QColor>
#include <QColorDialog>
#include <QPrintDialog>
#include <QPrinter>
#include <QTextCharFormat>
#include <QTextDocument>

QT_BEGIN_NAMESPACE
namespace Ui {
class EditorDeTexto;
}
QT_END_NAMESPACE

class EditorDeTexto : public QMainWindow
{
    Q_OBJECT

public:
    EditorDeTexto(QWidget *parent = nullptr);
    QString localfilename;
    QString all_files = "Arquivos de texto (*.txt);;Arquivos Markdown (*.md);;"
                        "Arquivos C (*.c);;Arquivos Python (*.py);;Arquivos C++ (*.cpp);;"
                        "Arquivos JavaScript (*.js);;Arquivos HTML (*.html);;Arquivos CSS (*.css);;"
                        "Todos os arquivos (*.*)";
    ~EditorDeTexto();

    void highlightOccurrences(const QString &text);

    void clearHighlight();  // Declaração da função clearHighlight

private slots:
    void on_actionNovo_triggered();

    void on_actionAbrir_triggered();

    void on_actionSalvar_Como_triggered();

    void on_actionSalvar_triggered();

    void on_actionSair_triggered();

    void on_actionCopiar_triggered();

    void on_actionColar_triggered();

    void on_actionRecortar_triggered();

    void on_actionRefazer_triggered();

    void on_actionDesfazer_triggered();

    void on_actionCor_triggered();

    void on_actionBackgroud_triggered();

    void on_actionFonte_triggered();

    void on_actionSobre_esse_programa_triggered();

    void on_actionImprimir_triggered();

    void on_actionPesquisar_triggered();

    void on_actionRetroceder_triggered();

    void on_actionAvan_ar_triggered();

    void on_actionEnumerar_Linhas_triggered();

private:
    Ui::EditorDeTexto *ui;

    QString searchText;

    QTextCursor currentHighlightCursor;  // Cursor da ocorrência atual
    QTextCharFormat currentHighlightFormat; // Formato para a ocorrência atual
    QTextCharFormat defaultHighlightFormat; // Formato para outras ocorrências
    void clearAllHighlights(); // Função para limpar todos os destaques

};
#endif // EDITORDETEXTO_H
