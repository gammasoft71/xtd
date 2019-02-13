# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.xtd.console.Debug:
/Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/Debug/libxtd.console.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/Debug/libxtd.console.a


PostBuild.xtd.console.Release:
/Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/Release/libxtd.console.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/Release/libxtd.console.a


PostBuild.xtd.console.MinSizeRel:
/Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/MinSizeRel/libxtd.console.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/MinSizeRel/libxtd.console.a


PostBuild.xtd.console.RelWithDebInfo:
/Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/RelWithDebInfo/libxtd.console.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/RelWithDebInfo/libxtd.console.a




# For each target create a dummy ruleso the target does not have to exist
