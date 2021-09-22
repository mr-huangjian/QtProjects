#ifndef MODEL_H
#define MODEL_H

#include <QVariant>
#include <QString>


class Model
{
public:
    Model();

    QString name;
};

Q_DECLARE_METATYPE(Model)

#endif // MODEL_H
