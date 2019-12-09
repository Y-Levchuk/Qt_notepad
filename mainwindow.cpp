#include <vector>
#include "mainwindow.h"
#include "ui_mainwindow.h"


static unsigned num = 0;

//головне вікно програми
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}
MainWindow::~MainWindow() {delete ui;}
static std::vector<QString> note,archive,home,just_note,com_a,com_b,com_c,proj2;//буффери, для збереження нотатків

/* on_actionAdd_triggered добавляє нотатку в буффер note, коли натискаємо на кнопку Add
 * textEdit - це текстовий редактор, де ми пишемо текст, відповідно ui->textEdit - звертаємося до редактора
 * i викликає метод toPlainText - який повертає текст  в редакторі*/
void MainWindow::on_actionAdd_triggered() {note.push_back(ui->textEdit->toPlainText());}

/*on_actionNew_triggered очищає текстовий редактор, кнопка Clear
 *textEdit->setText - метод, що повертає рядок в редактор,в нашому випадку пустий,
 *відповідно так стирається все, що було написано*/
void MainWindow::on_actionNew_triggered() {ui->textEdit->setText(QString());}

//on_actionAdd_to_archive_triggered - добавляє в архів нотатку, кнопка Add to archive
void MainWindow::on_actionAdd_to_archive_triggered()
{
    if(!note.empty()){
    archive.push_back(note[num]);
       auto tmp=note.begin();
       for(unsigned i=0;i<num;i++)tmp++;
       note.erase(tmp);
    }
}

//on_actionShow_all_Note_triggered показує всі нотатки в буффурі note 
void MainWindow::on_actionShow_all_Note_triggered()
{
    QString tmp="";
    for(auto a:note)tmp+=a+"\n____________________________________________\n";  //проходимся по вектру note, зописуємо всі нотатки в tmp
    ui->textEdit->setText(tmp);//виводимо tmp в редакторі
}
void MainWindow::on_actionShow_archive_triggered()
{
    QString tmp="";
    for(auto a:archive)tmp+=a+"\n____________________________________________\n";
    ui->textEdit->setText(tmp);
}
void MainWindow::on_actionShow_note_triggered()   {if(!note.empty())ui->textEdit->setText(note[num]);}//показує першу нотатку
void MainWindow::on_actionAdd_in_home_triggered() {if(!note.empty())home.push_back(note[num]);}//добавляє нотатку в буффер home
void MainWindow::on_actionproject2_triggered()    {if(!note.empty())proj2.push_back(note[num]);}//добавляє нотатку в буффер proj2
void MainWindow::on_actionComponent_A_triggered() {if(!note.empty())com_a.push_back(note[num]);}//добавляє нотатку в буффер com_a
void MainWindow::on_actionComponent_B_triggered() {if(!note.empty())com_b.push_back(note[num]);}//добавляє нотатку в буффер com_b
void MainWindow::on_actionComponent_C_triggered() {if(!note.empty())com_c.push_back(note[num]);}//добавляє нотатку в буффер com_c
void MainWindow::on_actionJust_note_triggered()   {if(!note.empty())just_note.push_back(note[num]);}//добавляє нотатку в буффер just_note
void MainWindow::on_actionNext_triggered()        {if(!note.empty())ui->textEdit->setText(note[num<note.size()-1?++num:num]);}//перехід між нотатками в буффері note
void MainWindow::on_actionBack_triggered()        {if(!note.empty())ui->textEdit->setText(note[num>0?--num:num]);}
//on_actionDelete_note_triggered видаляє нотатку
void MainWindow::on_actionDelete_note_triggered()
{
    if(!note.empty()){
        auto tmp=note.begin();
        for(unsigned i=0;i < num;i++)tmp++;
        note.erase(tmp);
        if(num > 0)--num;
    }
}
//показує увесь вміст буфферу home 
void MainWindow::on_actionShow_home_triggered()
{
    QString tmp="";
    for(auto a:home)tmp+=a+"\n____________________________________________\n";
    ui->textEdit->setText(tmp);
}
//показує увесь вміст буфферу just_note
void MainWindow::on_actionShow_just_note_triggered()
{
    QString tmp="";
    for(auto a:just_note)tmp+=a+"\n____________________________________________\n";
    ui->textEdit->setText(tmp);
}
//показує увесь вміст буфферу proj2
void MainWindow::on_actionshow_project2_triggered()
{
    QString tmp="";
    for(auto a:proj2)tmp+=a+"\n____________________________________________\n";
    ui->textEdit->setText(tmp);
}
//показує увесь вміст буфферу com_a
void MainWindow::on_actionShow_component_A_triggered()
{
    QString tmp="";
    for(auto a:com_a)tmp+=a+"\n____________________________________________\n";
    ui->textEdit->setText(tmp);
}
//показує увесь вміст буфферу come_b
void MainWindow::on_actionShow_component_B_triggered()
{
    QString tmp="";
    for(auto a:com_b)tmp+=a+"\n____________________________________________\n";
    ui->textEdit->setText(tmp);
}

//показує увесь вміст буфферу com_c
void MainWindow::on_actionShow_component_C_triggered()
{
    QString tmp="";
    for(auto a:com_c)tmp+=a+"\n____________________________________________\n";
    ui->textEdit->setText(tmp);
}