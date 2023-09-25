@echo off

if exist Files\Ciudades.dat del Files\Ciudades.dat
if exist Files\Proveedores.dat del Files\Proveedores.dat
if exist Files\Compras.dat del Files\Compras.dat
if exist Files\Articulos.dat del Files\Articulos.dat


copy Files\BackUp's\CIUDADES.BKP Files\Ciudades.dat
copy Files\BackUp's\PROVEEDORES.BKP Files\Proveedores.dat
copy Files\BackUp's\COMPRAS.BKP Files\Compras.dat
copy Files\BackUp's\ARTICULOS.BKP Files\Articulos.dat


pause