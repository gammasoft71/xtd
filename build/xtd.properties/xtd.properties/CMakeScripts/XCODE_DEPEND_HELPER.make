# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.xtd.properties.Debug:
/Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/Debug/libxtd.properties.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/Debug/libxtd.properties.a


PostBuild.xtd.properties.Release:
/Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/Release/libxtd.properties.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/Release/libxtd.properties.a


PostBuild.xtd.properties.MinSizeRel:
/Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/MinSizeRel/libxtd.properties.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/MinSizeRel/libxtd.properties.a


PostBuild.xtd.properties.RelWithDebInfo:
/Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/RelWithDebInfo/libxtd.properties.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/RelWithDebInfo/libxtd.properties.a




# For each target create a dummy ruleso the target does not have to exist
