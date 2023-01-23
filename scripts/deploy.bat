@ECHO off

if exist dist\ (
    set folderName=dist
) else (
    if exist build\ (
        set folderName=build
    ) else (
        goto ERROR
    )
)

git checkout --orphan gh-pages
yarn build
git --work-tree %folderName% add --all
git --work-tree commit -m gh-pages
git push origin HEAD:gh-pages --force
RMDIR %folderName%
git checkout -f docs
git branch -D gh-pages

ECHO Successfully deployed !
goto END

:ERROR
ECHO No dist/build folder found !

:END