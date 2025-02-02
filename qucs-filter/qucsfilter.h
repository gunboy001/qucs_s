/***************************************************************************
                                qucsfilter.h
                             -------------------
    begin                : Wed Mar 02 2005
    copyright            : (C) 2005 by Michael Margraf
    email                : michael.margraf@alumni.tu-berlin.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QUCSFILTER_H
#define QUCSFILTER_H

#include <QtGui>
#include <QtWidgets>
#include <QtCore>


class QGridLayout;
class QComboBox;
class QLineEdit;
class QLabel;
class QIntValidator;
class QDoubleValidator;

namespace spicecompat {
    enum Simulator {simNgspice = 0, simXyceSer = 1, simXycePar = 2, simSpiceOpus = 3, simQucsator = 4, simNotSpecified=10};
}

struct tQucsSettings {
  int x, y;      // position of main window
  QFont font;
  QString LangDir;
  QString Language;
  int DefaultSimulator;
};

extern struct tQucsSettings QucsSettings;

class QucsFilter : public QMainWindow
{
  Q_OBJECT
public:
  QucsFilter();
 ~QucsFilter();

private slots:
  void slotQuit();
  void slotHelpIntro();
  void slotHelpAbout();
  void slotHelpAboutQt();
  void slotCalculate();
  void slotTypeChanged(int);
  void slotClassChanged(int);
  void slotShowResult();
  void slotRealizationChanged(int);
  void slotTakeEr(const QString&);

private:
  void setError(const QString&);
  QString * calculateFilter(struct tFilter *);

  int ResultState;

  QGridLayout *all, *gbox1, *gbox2;
  QGroupBox *box1, *box2;
  QComboBox *ComboRealize, *ComboType, *ComboClass, *ComboCorner, *ComboStop, *ComboBandStop, *ComboEr;
  QLineEdit *EditOrder, *EditCorner, *EditStop, *EditRipple, *EditImpedance, *EditThickness, *EditHeight, *EditMinWidth, *EditMaxWidth;
  QLineEdit *EditAtten, *EditBandStop;
  QLabel *LabelRipple, *LabelRipple_dB, *LabelStart, *LabelStop, *LabelResult;
  QLabel *LabelAtten, *LabelAtten_dB, *LabelBandStop, *LabelOrder, *LabelImpedance, *LabelOhm;
  QIntValidator *IntVal;
  QDoubleValidator *DoubleVal;
};

#endif
