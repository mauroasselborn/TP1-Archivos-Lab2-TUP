@echo off

if exist files\Jugadores.dat del files\Jugadores.dat
if exist files\Deportes.dat del files\Deportes.dat


copy files\BackUps\JUGADORES.BKP files\Jugadores.dat
copy files\BackUps\DEPORTES.BKP files\Deportes.dat

pause>nul