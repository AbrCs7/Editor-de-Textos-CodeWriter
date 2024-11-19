/********************************************************************************
** Form generated from reading UI file 'editordetexto.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITORDETEXTO_H
#define UI_EDITORDETEXTO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditorDeTexto
{
public:
    QAction *actionNovo;
    QAction *actionAbrir;
    QAction *actionSalvar;
    QAction *actionSalvar_Como;
    QAction *actionSair;
    QAction *actionCopiar;
    QAction *actionColar;
    QAction *actionRecortar;
    QAction *actionRefazer;
    QAction *actionDesfazer;
    QAction *actionCor;
    QAction *actionBackgroud;
    QAction *actionFonte;
    QAction *actionSobre_esse_programa;
    QAction *actionImprimir;
    QAction *actionPesquisar;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuArquivo;
    QMenu *menuEditar;
    QMenu *menuFormatar;
    QMenu *menuSobre;
    QMenu *menuPesquisar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *EditorDeTexto)
    {
        if (EditorDeTexto->objectName().isEmpty())
            EditorDeTexto->setObjectName("EditorDeTexto");
        EditorDeTexto->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/edit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        EditorDeTexto->setWindowIcon(icon);
        actionNovo = new QAction(EditorDeTexto);
        actionNovo->setObjectName("actionNovo");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/file.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNovo->setIcon(icon1);
        actionAbrir = new QAction(EditorDeTexto);
        actionAbrir->setObjectName("actionAbrir");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/open.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionAbrir->setIcon(icon2);
        actionSalvar = new QAction(EditorDeTexto);
        actionSalvar->setObjectName("actionSalvar");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/save.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSalvar->setIcon(icon3);
        actionSalvar_Como = new QAction(EditorDeTexto);
        actionSalvar_Como->setObjectName("actionSalvar_Como");
        actionSair = new QAction(EditorDeTexto);
        actionSair->setObjectName("actionSair");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/close.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSair->setIcon(icon4);
        actionCopiar = new QAction(EditorDeTexto);
        actionCopiar->setObjectName("actionCopiar");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/copy.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionCopiar->setIcon(icon5);
        actionColar = new QAction(EditorDeTexto);
        actionColar->setObjectName("actionColar");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/paste.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionColar->setIcon(icon6);
        actionRecortar = new QAction(EditorDeTexto);
        actionRecortar->setObjectName("actionRecortar");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/cut.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionRecortar->setIcon(icon7);
        actionRefazer = new QAction(EditorDeTexto);
        actionRefazer->setObjectName("actionRefazer");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/redo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionRefazer->setIcon(icon8);
        actionDesfazer = new QAction(EditorDeTexto);
        actionDesfazer->setObjectName("actionDesfazer");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/undo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionDesfazer->setIcon(icon9);
        actionCor = new QAction(EditorDeTexto);
        actionCor->setObjectName("actionCor");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/img/highlight.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionCor->setIcon(icon10);
        actionBackgroud = new QAction(EditorDeTexto);
        actionBackgroud->setObjectName("actionBackgroud");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/img/background.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionBackgroud->setIcon(icon11);
        actionFonte = new QAction(EditorDeTexto);
        actionFonte->setObjectName("actionFonte");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/img/font.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionFonte->setIcon(icon12);
        actionSobre_esse_programa = new QAction(EditorDeTexto);
        actionSobre_esse_programa->setObjectName("actionSobre_esse_programa");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/img/about.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSobre_esse_programa->setIcon(icon13);
        actionImprimir = new QAction(EditorDeTexto);
        actionImprimir->setObjectName("actionImprimir");
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/img/print.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionImprimir->setIcon(icon14);
        actionPesquisar = new QAction(EditorDeTexto);
        actionPesquisar->setObjectName("actionPesquisar");
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/img/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionPesquisar->setIcon(icon15);
        centralwidget = new QWidget(EditorDeTexto);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 20, 781, 511));
        textEdit->setStyleSheet(QString::fromUtf8(""));
        EditorDeTexto->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EditorDeTexto);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menuArquivo = new QMenu(menubar);
        menuArquivo->setObjectName("menuArquivo");
        menuEditar = new QMenu(menubar);
        menuEditar->setObjectName("menuEditar");
        menuFormatar = new QMenu(menubar);
        menuFormatar->setObjectName("menuFormatar");
        menuSobre = new QMenu(menubar);
        menuSobre->setObjectName("menuSobre");
        menuPesquisar = new QMenu(menubar);
        menuPesquisar->setObjectName("menuPesquisar");
        EditorDeTexto->setMenuBar(menubar);
        statusbar = new QStatusBar(EditorDeTexto);
        statusbar->setObjectName("statusbar");
        EditorDeTexto->setStatusBar(statusbar);
        toolBar = new QToolBar(EditorDeTexto);
        toolBar->setObjectName("toolBar");
        toolBar->setMovable(false);
        EditorDeTexto->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menuArquivo->menuAction());
        menubar->addAction(menuEditar->menuAction());
        menubar->addAction(menuPesquisar->menuAction());
        menubar->addAction(menuFormatar->menuAction());
        menubar->addAction(menuSobre->menuAction());
        menuArquivo->addAction(actionNovo);
        menuArquivo->addAction(actionAbrir);
        menuArquivo->addAction(actionSalvar);
        menuArquivo->addAction(actionSalvar_Como);
        menuArquivo->addAction(actionImprimir);
        menuArquivo->addSeparator();
        menuArquivo->addAction(actionSair);
        menuEditar->addAction(actionCopiar);
        menuEditar->addAction(actionColar);
        menuEditar->addAction(actionRecortar);
        menuEditar->addSeparator();
        menuEditar->addAction(actionRefazer);
        menuEditar->addAction(actionDesfazer);
        menuFormatar->addAction(actionCor);
        menuFormatar->addAction(actionBackgroud);
        menuFormatar->addAction(actionFonte);
        menuSobre->addAction(actionSobre_esse_programa);
        menuPesquisar->addAction(actionPesquisar);
        toolBar->addAction(actionNovo);
        toolBar->addAction(actionAbrir);
        toolBar->addAction(actionSalvar);
        toolBar->addAction(actionImprimir);
        toolBar->addSeparator();
        toolBar->addAction(actionCopiar);
        toolBar->addAction(actionColar);
        toolBar->addAction(actionRecortar);
        toolBar->addAction(actionRefazer);
        toolBar->addAction(actionDesfazer);
        toolBar->addSeparator();
        toolBar->addAction(actionPesquisar);

        retranslateUi(EditorDeTexto);

        QMetaObject::connectSlotsByName(EditorDeTexto);
    } // setupUi

    void retranslateUi(QMainWindow *EditorDeTexto)
    {
        EditorDeTexto->setWindowTitle(QCoreApplication::translate("EditorDeTexto", "Editor de Texto", nullptr));
        actionNovo->setText(QCoreApplication::translate("EditorDeTexto", "Novo", nullptr));
#if QT_CONFIG(shortcut)
        actionNovo->setShortcut(QCoreApplication::translate("EditorDeTexto", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbrir->setText(QCoreApplication::translate("EditorDeTexto", "Abrir", nullptr));
#if QT_CONFIG(shortcut)
        actionAbrir->setShortcut(QCoreApplication::translate("EditorDeTexto", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSalvar->setText(QCoreApplication::translate("EditorDeTexto", "Salvar", nullptr));
#if QT_CONFIG(shortcut)
        actionSalvar->setShortcut(QCoreApplication::translate("EditorDeTexto", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSalvar_Como->setText(QCoreApplication::translate("EditorDeTexto", "Salvar Como", nullptr));
        actionSair->setText(QCoreApplication::translate("EditorDeTexto", "Sair", nullptr));
        actionCopiar->setText(QCoreApplication::translate("EditorDeTexto", "Copiar", nullptr));
#if QT_CONFIG(shortcut)
        actionCopiar->setShortcut(QCoreApplication::translate("EditorDeTexto", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionColar->setText(QCoreApplication::translate("EditorDeTexto", "Colar", nullptr));
#if QT_CONFIG(shortcut)
        actionColar->setShortcut(QCoreApplication::translate("EditorDeTexto", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRecortar->setText(QCoreApplication::translate("EditorDeTexto", "Recortar", nullptr));
#if QT_CONFIG(shortcut)
        actionRecortar->setShortcut(QCoreApplication::translate("EditorDeTexto", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRefazer->setText(QCoreApplication::translate("EditorDeTexto", "Refazer", nullptr));
        actionDesfazer->setText(QCoreApplication::translate("EditorDeTexto", "Desfazer", nullptr));
        actionCor->setText(QCoreApplication::translate("EditorDeTexto", "Cor", nullptr));
        actionBackgroud->setText(QCoreApplication::translate("EditorDeTexto", "Backgroud", nullptr));
        actionFonte->setText(QCoreApplication::translate("EditorDeTexto", "Fonte", nullptr));
        actionSobre_esse_programa->setText(QCoreApplication::translate("EditorDeTexto", "Sobre esse programa", nullptr));
        actionImprimir->setText(QCoreApplication::translate("EditorDeTexto", "Imprimir", nullptr));
#if QT_CONFIG(shortcut)
        actionImprimir->setShortcut(QCoreApplication::translate("EditorDeTexto", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPesquisar->setText(QCoreApplication::translate("EditorDeTexto", "Pesquisar", nullptr));
        menuArquivo->setTitle(QCoreApplication::translate("EditorDeTexto", "Arquivo", nullptr));
        menuEditar->setTitle(QCoreApplication::translate("EditorDeTexto", "Editar", nullptr));
        menuFormatar->setTitle(QCoreApplication::translate("EditorDeTexto", "Formatar", nullptr));
        menuSobre->setTitle(QCoreApplication::translate("EditorDeTexto", "Sobre", nullptr));
        menuPesquisar->setTitle(QCoreApplication::translate("EditorDeTexto", "Pesquisar", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("EditorDeTexto", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditorDeTexto: public Ui_EditorDeTexto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITORDETEXTO_H
