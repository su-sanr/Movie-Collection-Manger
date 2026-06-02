include("/home/alex/Documents/hw/oop/Project/Movie_Collection_Manager/build/Desktop_Qt_6_11_0-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/Movie_Collection_Manager-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "/home/alex/Documents/hw/oop/Project/Movie_Collection_Manager/build/Desktop_Qt_6_11_0-Debug/Movie_Collection_Manager"
    GENERATE_QT_CONF
)
