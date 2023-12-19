#include "buttongroup.h"

ButtonGroup::ButtonGroup(string title_string,
			 vector<QPushButton *> buttons,
			 string nothing_to_show_string,
			 QWidget *parent)
    : QWidget(parent)
    , title_string_(QString::fromStdString(title_string))
    , nothing_to_show_string_(QString::fromStdString(nothing_to_show_string))
    , buttons_(buttons)
{
  title_ = new QLabel();
  nothing_to_show_label_ = new QLabel(nothing_to_show_string_);
}

void ButtonGroup::show()
{
  QVBoxLayout *layout = new QVBoxLayout(this);

  title_->setText(title_string_);
  layout->addWidget(title_);

  for (QPushButton *btn : buttons_) {
    layout->addWidget(btn);
  }
}
