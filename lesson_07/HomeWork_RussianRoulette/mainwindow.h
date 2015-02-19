#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

  // Номер раунда
  int round;

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

  void log(QString s);

 private slots:
  void on_playButton_clicked();

 private:
  Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
