#include "draw.h"
#include <QtGui>

Draw::Draw(QWidget *parent) : QWidget(parent)
{

}

 void Draw::mousePressEvent(QMouseEvent *event)
 {
     //Get coordinates
     int x = event->x();
     int y = event->y();

     //Add to the list
     QPoint q(x, y);
     points.push_back(q);

     //Repaint screen
     repaint();

 }

 void Draw::paintEvent(QPaintEvent *e)
 {
     QPainter qp(this);
     qp.begin(this);

     // Draw points
     for(int i=0; i< points.size(); i++)
     {
         qp.drawEllipse(points[i].x() - 3, points[i].y() - 3, 6, 6);
     }

     // Draw Ch
     qp.drawPolygon(ch);
     qp.end();

     }
