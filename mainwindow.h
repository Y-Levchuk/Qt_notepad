#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
void on_actionAdd_triggered();
void on_actionNew_triggered();
void on_actionAdd_to_archive_triggered();
void on_actionShow_all_Note_triggered();
void on_actionShow_note_triggered();
void on_actionShow_archive_triggered();
void on_actionAdd_in_home_triggered();
void on_actionproject2_triggered();
void on_actionComponent_A_triggered();
void on_actionComponent_B_triggered();
void on_actionComponent_C_triggered();
void on_actionJust_note_triggered();
void on_actionDelete_note_triggered();
void on_actionNext_triggered();
void on_actionBack_triggered();
void on_actionShow_home_triggered();
void on_actionShow_just_note_triggered();
void on_actionshow_project2_triggered();
void on_actionShow_component_A_triggered();
void on_actionShow_component_B_triggered();
void on_actionShow_component_C_triggered();

private:
    Ui::MainWindow *ui;
};
#endif 
