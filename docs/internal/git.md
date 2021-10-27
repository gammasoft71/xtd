# Some useful git commands

## Clone

In general this command is done only once.
Clone a remote project locally in your working folder:

```
cd Projects\xtd
git clone https://github.com/gammasoft71/xtd
```

## Status

You are automatically on the master branch, you can check by typing the command

```
git status
```

## Pull

Every time you want to resynchronize your local repo with the remote repo to get the latest changes

```
git pull
```

## Creation of a branch

If you want to create a dev branch 

```
git branch my_branch_dev1
```

You have just created the branch but you are still on the active master branch.

## Checkout

If you want to work on your my_branch_dev1 branch

```
git checkout my_branch_dev1
```

The active branch is now my_branch_dev1.

If you want to go back to your master branch

```
git checkout master
```

The active branch is now master.

## Commit

When you want to commit your files to any active branch

```
git commit -m "My commit message" --all
```

or for a specific file

```
git commit -m "My commit message" my_class.h
```

## Merge

When you want to merge your dev branch into master

```
git checkout master
git merge my_branch_dev1
```

## Remove branch

When you want to remove your dev branch

```
git branch -d my_branch_dev1
```

## GitHub Desktop application

When you have understood the principles of git branches and git commands, the easiest way is to use the [GitHub Desktop](https://desktop.github.com) application.
