#include "resources_ui.h"


Resources_ui::Resources_ui(Qt3DCore::QEntity *rootEntity)
    :root_Entity (rootEntity)
{

    Resources_Entity=new Qt3DCore::QEntity(root_Entity);

    Resources_ui_mesh= new Qt3DRender::QMesh(Resources_Entity);

    Resources_transform = new Qt3DCore::QTransform();

    Texture_loader=new  Qt3DRender::QTextureLoader(Resources_Entity);

    Material = new Qt3DExtras::QTextureMaterial(Resources_Entity);
    Material->setTexture(Texture_loader);

    Qt3DExtras::QPhongMaterial *phongMaterial = new Qt3DExtras::QPhongMaterial();
    phongMaterial->setDiffuse(QColor(75, 75, 75)); // Safari Yellow #cccd4b
    phongMaterial->setSpecular(Qt::white);
    Resources_Entity->addComponent(phongMaterial);
    Resources_Entity->addComponent(phongMaterial);

}

Resources_ui::~Resources_ui()
{
    delete root_Entity;
    delete Resources_transform;
    delete Resources_Entity;
    delete Resources_ui_mesh;
    delete Texture_loader;
    delete Material;
}


void Resources_ui::Add_resources_components()
{
    Resources_Entity->addComponent(Resources_ui_mesh);
    Resources_Entity->addComponent(Resources_transform);
    Resources_Entity->addComponent(Material);
}
