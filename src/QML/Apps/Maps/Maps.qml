import QtQuick 2.0
import QtPositioning 5.5
import QtLocation 5.9




Map {
    center: QtPositioning.coordinate(-34.9286600, 138.5986300) // Adelaide
    zoomLevel: 12
    plugin: Plugin {
        name: "mapboxgl"
        PluginParameter {
            name: "mapboxgl.access_token"
            value: "pk.eyJ1Ijoia2V2aW5kb3ZldG9uIiwiYSI6ImNpdGdsYm9zYTAxMmcydG1rMnhuMGkxbHkifQ.pfUpUrZVbxkcj_pDx4Pbeg"
        }
    }

    MapHeader {
        x: 0
//        y: parent.height - height
        y: 0
        z: 2
    }


//        MapParameter {
//                type: "source"

//                property var name: "routeSource"
//                property var sourceType: "geojson"
//                property var data: '{ "type": "FeatureCollection", "features": \
//                    [{ "type": "Feature", "properties": {}, "geometry": { \
//                    "type": "LineString", "coordinates": [[ 24.934938848018646, \
//                    60.16830257086771 ], [ 24.943315386772156, 60.16227776476442 ]]}}]}'
//            }

//            MapParameter {
//                type: "layer"

//                property var name: "route"
//                property var layerType: "line"
//                property var source: "routeSource"
//            }

//            MapParameter {
//                type: "paint"

//                property var layer: "route"
//                property var lineColor: "blue"
//                property var lineWidth: 8.0
//            }

//            MapParameter {
//                type: "layout"

//                property var layer: "route"
//                property var lineJoin: "round"
//                property var lineCap: "round"
//            }

}
