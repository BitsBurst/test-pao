//
// Created by thebitninja on 12/27/23.
//

#include "CreateView.h"

CreateView::CreateView(QWidget *p): ViewAbstract(p) {
    setSizePolicy(QSizePolicy:: Expanding, QSizePolicy ::Expanding );
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
}