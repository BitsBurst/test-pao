#ifndef BUTTONGROUP_H
#define BUTTONGROUP_H

#include <QLabel>
#include <QObject>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include <string>
#include <vector>

using std::string;
using std::vector;

class ButtonGroup : public QWidget
{
  Q_OBJECT

private:
  QString title_string_;
  QString nothing_to_show_string_;

  QLabel *title_;
  QLabel *nothing_to_show_label_;
  vector<QPushButton *> buttons_;

public:
  ButtonGroup(string title_string = "",
	      vector<QPushButton *> buttons = vector<QPushButton *>(),
	      string nothing_to_show_string = "Nothing to show!",
	      QWidget *parent = nullptr);
  void show();
};

#endif // BUTTONGROUP_H
