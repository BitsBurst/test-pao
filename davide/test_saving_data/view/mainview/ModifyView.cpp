//
// Created by thebitninja on 12/27/23.
//

#include "ModifyView.h"

ModifyView::ModifyView(QWidget *p): ViewAbstract(p) {
    setSizePolicy(QSizePolicy:: Expanding, QSizePolicy ::Expanding );
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::gray);
    setAutoFillBackground(true);
    setPalette(pal);
}
