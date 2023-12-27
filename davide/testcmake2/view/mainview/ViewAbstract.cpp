//
// Created by thebitninja on 12/27/23.
//

#include "ViewAbstract.h"

ViewAbstract::ViewAbstract(QWidget *p, bool visible): QWidget(p){
    setVisible(visible);
}
