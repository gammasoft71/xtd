# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.xtd.delegates.Debug:
/Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/Debug/libxtd.delegates.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/Debug/libxtd.delegates.a


PostBuild.xtd.delegates.Release:
/Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/Release/libxtd.delegates.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/Release/libxtd.delegates.a


PostBuild.xtd.delegates.MinSizeRel:
/Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/MinSizeRel/libxtd.delegates.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/MinSizeRel/libxtd.delegates.a


PostBuild.xtd.delegates.RelWithDebInfo:
/Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/RelWithDebInfo/libxtd.delegates.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/RelWithDebInfo/libxtd.delegates.a




# For each target create a dummy ruleso the target does not have to exist
