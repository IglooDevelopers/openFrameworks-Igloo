@echo off
set "SRC=libs"
set "DST=..\libs"

robocopy "%SRC%" "%DST%" /E /MT

echo copy done