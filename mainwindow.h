#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QByteArray>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    private:
        Q_OBJECT
            Ui::MainWindow *ui;
        bool isError;
        void setAnd(const QByteArray a, const QByteArray b);
        void setOr(const QByteArray a, const QByteArray b);
        void setNot(const QByteArray a, const QByteArray b);
        void setNand(const QByteArray a, const QByteArray b);
        void setNor(const QByteArray a, const QByteArray b);
        void setXor(const QByteArray a, const QByteArray b);
        void setXnor(const QByteArray a, const QByteArray b);

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

        public slots:
            void processInputs();

};
#endif
