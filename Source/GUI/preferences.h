#ifndef PREFERENCES_H
#define PREFERENCES_H

#include "Core/Core.h"
#include <QDialog>
#include <QList>
#include <tuple>

namespace Ui {
class Preferences;
}

class Preferences : public QDialog
{
    Q_OBJECT

public:
    explicit Preferences(QWidget *parent = 0);
    ~Preferences();

    //Preferences
    activefilters ActiveFilters;
    activealltracks ActiveAllTracks;

    QList<std::tuple<int, int>> loadFilterSelectorsOrder();
    void saveFilterSelectorsOrder(const QList<std::tuple<int, int>>& order);

private:
    Ui::Preferences *ui;

    void Load();
    void Save();

 private Q_SLOTS:
    void OnAccepted();
    void OnRejected();
};

#endif // PREFERENCES_H
