#include "baseboard_ui.h"

BaseBoard_ui::BaseBoard_ui(Qt3DCore::QEntity *Table_Entitiy)
    : Material_Board(new Qt3DExtras::QNormalDiffuseSpecularMapMaterial())
    , diffuseTexture(Material_Board->diffuse())
    , normalTexture(Material_Board->normal())
    , specularTexture(Material_Board->specular())
{

    Board_Entity=new Qt3DCore::QEntity(Table_Entitiy);
    Board_Entity->setParent(Table_Entitiy);

    Board_ui_mesh= new Qt3DRender::QMesh();
    Board_ui_mesh->setSource(QUrl(QStringLiteral("path")));
    Board_Entity->addComponent(Board_ui_mesh);

    Board_transform = new Qt3DCore::QTransform();
    Board_transform->setScale(0.10f);       // size
    Board_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 1.0f, 2.0f), 0.0f)); // x,y,z axis and degree rotation
    Board_transform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));
    Board_Entity->addComponent(Board_transform);

    DiffuseTextureImage=new Qt3DRender::QTextureImage();
    DiffuseTextureImage->setSource(QUrl(QStringLiteral("path")));

    NormalTextureImage=new Qt3DRender::QTextureImage();
    NormalTextureImage->setSource(QUrl(QStringLiteral("path")));

    SpecularTextureImage=new Qt3DRender::QTextureImage();
    SpecularTextureImage->setSource(QUrl(QStringLiteral("path")));

    diffuseTexture->addTextureImage(DiffuseTextureImage);
    normalTexture->addTextureImage(NormalTextureImage);
    specularTexture->addTextureImage(SpecularTextureImage);

}
