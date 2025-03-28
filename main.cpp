#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include "person.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QStringList continentList;
    QQuickStyle::setStyle("Material");
    continentList.append("Africa");
    continentList.append("Europe");
    continentList.append("America");
    continentList.append("Asia");
    continentList.append("Oceania");
    continentList.append("Antarctica");
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("continentModel",continentList);
    engine.rootContext()->setContextProperties(QList<QQmlContext::PropertyPair>{
        {"itemList1", QStringList{"List1Item1", "List1Item2", "List1Item3"}},
        {"itemList2",QStringList{"List2Item1", "List2Item2", "List2Item3"}}
    });
    QList<QObject *> personList;
    personList.append(new Person("John Doe C++","green",32,&engine));
    personList.append(new Person("Mary Green","blue",23,&engine));
    personList.append(new Person("Mitch Nathson","dodgerblue",30,&engine));
    personList.append(new Person("Daniel Sten","red",67,&engine));
    personList.append(new Person("John Doe C++","green",32,&engine));
    personList.append(new Person("Mary Green","blue",23,&engine));
    personList.append(new Person("Mitch Nathson","dodgerblue",30,&engine));
    personList.append(new Person("Daniel Sten","red",67,&engine));
    personList.append(new Person("John Doe C++","green",32,&engine));
    personList.append(new Person("Mary Green","blue",23,&engine));
    personList.append(new Person("Mitch Nathson","dodgerblue",30,&engine));
    personList.append(new Person("Daniel Sten","red",67,&engine));
    personList.append(new Person("John Doe C++","green",32,&engine));
    personList.append(new Person("Mary Green","blue",23,&engine));
    personList.append(new Person("Mitch Nathson","dodgerblue",30,&engine));
    personList.append(new Person("Daniel Sten","red",67,&engine));
    engine.rootContext()->setContextProperty("personModel",QVariant::fromValue(personList));

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("qtAdvance", "Main");

    return app.exec();
}
