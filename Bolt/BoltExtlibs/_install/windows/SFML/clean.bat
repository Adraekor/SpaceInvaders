@echo off
echo /////////%0 start

cd %SRC_ROOT%/SFML

@echo on
git add .
git reset --hard
git checkout master
rmdir /s /q _build
git clean -f -d -x
@echo off

echo /////////%0 done