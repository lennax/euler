# installer
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-${LIBRARY_VERSION}")
set(CPACK_GENERATOR "DEB")
set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")
set(CPACK_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
set(CPACK_SET_DESTDIR TRUE)
set(CPACK_PACKAGE_CONTACT "James Goppert james.goppert@gmail.com")
set(CPACK_PACKAGE_DESCRITION_SUMMARY "
    The Open Object Oriented Autonomous Robotics Kit

    This library is useful for controller design for unmanned
	vehicles. It has a trim gui based on qt that can be used
    to craete a linaer model of JSBSim flight dynamic model.
    This model can then be used in the Scicoslab toolbox
    provided for controller design. A simple bicyle model
    for ground vehicles is also implemented in one of the
    demonstration blocks. Hardware in the loop simulation
    is enabled via the MAVLINK protocol.	
	")
set(CPACK_SOURCE_IGNORE_FILES ${CPACK_SOURCE_IGNORE_FILES}
	/.git/;/build/;~$;.*\\\\.bin$;.*\\\\.swp$)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README")
set(CPACK_PACKAGE_VERSION_MAJOR ${APPLICATION_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${APPLICATION_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${APPLICATION_VERSION_PATCH})
include(CPack)
