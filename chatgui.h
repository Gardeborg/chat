#ifndef CHATGUI_H
#define CHATGUI_H
#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextDocument>

class chatGui : public QWidget
{
    Q_OBJECT

public:
    chatGui(QWidget *parent = 0);
    ~chatGui();

private slots:
    void onSend();

private:
    QTextEdit historyTextEdit;
    QTextEdit textEdit;
    QVBoxLayout mainLayout;
    QHBoxLayout bottomLayout;
    QPushButton sendButton;
    QTextDocument currentChatDocument;
};

#endif // CHATGUI_H
