# All variables and this file are optional, if they are not present the PG and the
# makefiles will try to parse the correct values from the file system.
#
# Variables that specify exclusions can use % as a wildcard to specify that anything in
# that position will match. A partial path can also be specified to, for example, exclude
# a whole folder from the parsed paths from the file system
#
# Variables can be specified using = or +=
# = will clear the contents of that variable both specified from the file or the ones parsed
# from the file system
# += will add the values to the previous ones in the file or the ones parsed from the file
# system
#
# The PG can be used to detect errors in this file, just create a new project with this addon
# and the PG will write to the console the kind of error and in which line it is

meta:
	ADDON_NAME = ofxXimea
	ADDON_DESCRIPTION = Addon for using the Ximea xIQ and xIC cameras with openframeworks
	ADDON_AUTHOR = Nathan Wade, Andreas Schmelas
	ADDON_TAGS = "computer vision" "opencv" "image processing" "camera"
	ADDON_URL = https://github.com/m9dfukc/ofxXimea