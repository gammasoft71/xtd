# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.xtd.Debug:
/Users/yves/Projects/xtd/xtd/build/xtd/Debug/libxtd.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd/Debug/libxtd.a


PostBuild.xtd.console.Debug:
/Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/Debug/libxtd.console.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/Debug/libxtd.console.a


PostBuild.xtd.delegates.Debug:
/Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/Debug/libxtd.delegates.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/Debug/libxtd.delegates.a


PostBuild.xtd.properties.Debug:
/Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/Debug/libxtd.properties.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/Debug/libxtd.properties.a


PostBuild.xtd.strings.Debug:
/Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/Debug/libxtd.strings.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/Debug/libxtd.strings.a


PostBuild.xtd.Release:
/Users/yves/Projects/xtd/xtd/build/xtd/Release/libxtd.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd/Release/libxtd.a


PostBuild.xtd.console.Release:
/Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/Release/libxtd.console.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/Release/libxtd.console.a


PostBuild.xtd.delegates.Release:
/Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/Release/libxtd.delegates.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/Release/libxtd.delegates.a


PostBuild.xtd.properties.Release:
/Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/Release/libxtd.properties.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/Release/libxtd.properties.a


PostBuild.xtd.strings.Release:
/Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/Release/libxtd.strings.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/Release/libxtd.strings.a


PostBuild.xtd.MinSizeRel:
/Users/yves/Projects/xtd/xtd/build/xtd/MinSizeRel/libxtd.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd/MinSizeRel/libxtd.a


PostBuild.xtd.console.MinSizeRel:
/Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/MinSizeRel/libxtd.console.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/MinSizeRel/libxtd.console.a


PostBuild.xtd.delegates.MinSizeRel:
/Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/MinSizeRel/libxtd.delegates.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/MinSizeRel/libxtd.delegates.a


PostBuild.xtd.properties.MinSizeRel:
/Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/MinSizeRel/libxtd.properties.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/MinSizeRel/libxtd.properties.a


PostBuild.xtd.strings.MinSizeRel:
/Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/MinSizeRel/libxtd.strings.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/MinSizeRel/libxtd.strings.a


PostBuild.xtd.RelWithDebInfo:
/Users/yves/Projects/xtd/xtd/build/xtd/RelWithDebInfo/libxtd.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd/RelWithDebInfo/libxtd.a


PostBuild.xtd.console.RelWithDebInfo:
/Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/RelWithDebInfo/libxtd.console.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.console/xtd.console/RelWithDebInfo/libxtd.console.a


PostBuild.xtd.delegates.RelWithDebInfo:
/Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/RelWithDebInfo/libxtd.delegates.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.delegates/xtd.delegates/RelWithDebInfo/libxtd.delegates.a


PostBuild.xtd.properties.RelWithDebInfo:
/Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/RelWithDebInfo/libxtd.properties.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.properties/xtd.properties/RelWithDebInfo/libxtd.properties.a


PostBuild.xtd.strings.RelWithDebInfo:
/Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/RelWithDebInfo/libxtd.strings.a:
	/bin/rm -f /Users/yves/Projects/xtd/xtd/build/xtd.strings/xtd.strings/RelWithDebInfo/libxtd.strings.a




# For each target create a dummy ruleso the target does not have to exist
