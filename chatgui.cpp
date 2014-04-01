#include "chatgui.h"
#include <QKeySequence>
#include <QShortcut>

chatGui::chatGui(QWidget *parent)
    : QWidget(parent),
      historyTextEdit(),
      textEdit(),
      mainLayout(),
      bottomLayout(),
      sendButton("Send")
{
    mainLayout.addWidget(&historyTextEdit);
    bottomLayout.addWidget(&textEdit);
    bottomLayout.addWidget(&sendButton);
    mainLayout.addLayout(&bottomLayout);
    this->setLayout(&mainLayout);

    historyTextEdit.setReadOnly(true);

    connect(&sendButton, SIGNAL(clicked()), this, SLOT(onSend()));
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+O"), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(onSend()));
}

chatGui::~chatGui()
{

}

void chatGui::onSend() {
    QString text = textEdit.document()->toPlainText();
    textEdit.document()->setPlainText("");
    QString historyText = historyTextEdit.document()->toPlainText();
    QChar endl('\n');
    if(text[text.size()-1] != endl) {
        text.append("\n");
    }
    historyTextEdit.document()->setPlainText(historyText + text);
}
