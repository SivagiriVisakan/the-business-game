#ifndef RESORCES_UI_H
#define RESORCES_UI_H


#include <QtCore/QObject>
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>
#include <Qt3DExtras/QTorusMesh>
#include<Qt3DExtras/QPhongMaterial>
#include<Qt3DExtras>
#include<QtCore/QDebug>

class Resources_ui : public QObject
{
    Q_OBJECT

public:

    void Add_resources_components();

    explicit Resources_ui(Qt3DCore::QEntity *rootEntity);
    ~Resources_ui();

private:
    Qt3DCore::QEntity *root_Entity;
    Qt3DCore::QEntity *Resources_Entity;
    Qt3DRender::QMesh *Resources_ui_mesh;
    Qt3DCore::QTransform *Resources_transform;

    Qt3DRender::QTextureLoader *Texture_loader;
    Qt3DExtras::QTextureMaterial *Material ;


    friend class Base_ui ;
    friend class Player_selection;
    friend class Cube_ui;

};


#endif // RESORCES_UI_H
