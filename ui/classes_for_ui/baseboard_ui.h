#ifndef BASEBOARD_H
#define BASEBOARD_H

#include <QtCore/QObject>
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>
#include <Qt3DExtras/QTorusMesh>
#include<Qt3DExtras/QPhongMaterial>
#include<Qt3DExtras>
#include<QtCore/QDebug>

class BaseBoard_ui : public QObject
{
    Q_OBJECT

public:
    explicit BaseBoard_ui(Qt3DCore::QEntity *Table_Entity);
    ~ BaseBoard_ui();

private:
    Qt3DCore::QEntity *Board_Entity;
    Qt3DRender::QMesh *Board_ui_mesh;
    Qt3DCore::QTransform *Board_transform;

    Qt3DExtras::QNormalDiffuseSpecularMapMaterial *Material_Board;
    Qt3DRender::QAbstractTexture *diffuseTexture;
    Qt3DRender::QAbstractTexture *normalTexture;
    Qt3DRender::QAbstractTexture *specularTexture;
    Qt3DRender::QTextureImage *DiffuseTextureImage;
    Qt3DRender::QTextureImage *NormalTextureImage;
    Qt3DRender::QTextureImage *SpecularTextureImage;

};

#endif // BASEBOARD_H
