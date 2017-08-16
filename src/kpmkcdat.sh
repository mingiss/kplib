# ------------------------------
# file PojData.h creation
#
# add command
#   ../kplib/src/kpmkcdat.sh my_project > ProjData.h
# to the project build script
#
# 2016-09-06  mp  migration of kpsgrp from tv to kplib
#
echo \#pragma once
echo "#include \"$1.h\""
echo "#define PROJ_NAME _T(\"$1\")"
# date +"#define PROJ_DATE _T(\"%Y-%m-%d\")"
date +"#define PROJ_DATE _T(\"%Y-%m-%d %H:%M:%S\")"
