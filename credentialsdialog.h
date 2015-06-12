/*

    Copyright (c) 2015 Oliver Lau <ola@ct.de>, Heise Medien GmbH & Co. KG

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef __CREDENTIALSDIALOG_H_
#define __CREDENTIALSDIALOG_H_

#include <QDialog>
#include <QShowEvent>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class CredentialsDialog;
}

class CredentialsDialog : public QDialog
{
  Q_OBJECT

  Q_PROPERTY(QString masterPassword READ masterPassword)

public:
  explicit CredentialsDialog(QWidget *parent = nullptr);
  ~CredentialsDialog();

  void invalidatePassword(void);

  void setRepeatPassword(bool);

  QString masterPassword(void) const;

public slots:
  virtual void reject(void);

protected:
  void showEvent(QShowEvent *);

private slots:
  void okClicked(void);
  void comparePasswords(void);

private:
  Ui::CredentialsDialog *ui;

  QLineEdit *mRepeatPasswordLineEdit;
};

#endif // __CREDENTIALSDIALOG_H_
