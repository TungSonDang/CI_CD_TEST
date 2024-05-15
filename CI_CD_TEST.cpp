// Copyright 2024 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

#include "CI_CD_TEST.h"

#include "Map.h"
#include "MapQuickView.h"
#include "MapTypes.h"

using namespace Esri::ArcGISRuntime;

CI_CD_TEST::CI_CD_TEST(QObject *parent /* = nullptr */)
    : QObject(parent)
    , m_map(new Map(BasemapStyle::ArcGISStreetsNight, this))
{}

CI_CD_TEST::~CI_CD_TEST() {}

MapQuickView *CI_CD_TEST::mapView() const
{
    return m_mapView;
}

// Set the view (created in QML)
void CI_CD_TEST::setMapView(MapQuickView *mapView)
{
    if (!mapView || mapView == m_mapView) {
        return;
    }

    m_mapView = mapView;
    m_mapView->setMap(m_map);

    emit mapViewChanged();
}
