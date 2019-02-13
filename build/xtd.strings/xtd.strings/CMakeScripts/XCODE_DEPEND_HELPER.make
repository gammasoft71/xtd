# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.xtd.strings.Debug:
/Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/Debug/libxtd.strings.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/Debug/libxtd.strings.a


PostBuild.xtd.strings.Release:
/Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/Release/libxtd.strings.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/Release/libxtd.strings.a


PostBuild.xtd.strings.MinSizeRel:
/Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/MinSizeRel/libxtd.strings.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/MinSizeRel/libxtd.strings.a


PostBuild.xtd.strings.RelWithDebInfo:
/Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/RelWithDebInfo/libxtd.strings.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/RelWithDebInfo/libxtd.strings.a




# For each target create a dummy ruleso the target does not have to exist
