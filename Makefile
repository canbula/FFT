CC = g++ `wx-config --cxxflags --libs`
OS := $(shell uname)
ifeq ($(OS), Darwin)
ALLTARGET := FFT.app
INSTALLTARGET := cp -Rf FFT.app /Applications/FFT.app
UNINSTALLTARGET := rm -Rf /Applications/FFT.app
CLEANTARGET := rm -Rf FFT.app
else
ALLTARGET := FFT
INSTALLTARGET := cp -Rf ${CURDIR} /usr/share/FFT
INSTALLTARGET += ;ln -s /usr/share/FFT/FFT /bin/FFT
INSTALLTARGET += ;ln -s /usr/share/FFT/resource/FFT.xpm /usr/share/pixmaps/FFT.xpm
INSTALLTARGET += ;cp -f ${CURDIR}/resource/FFT.desktop /usr/share/applications/FFT.desktop
UNINSTALLTARGET := rm -Rf /usr/share/FFT
UNINSTALLTARGET += ;rm -f /usr/share/applications/FFT.desktop
UNINSTALLTARGET += ;rm -f /usr/share/pixmaps/FFT.xpm
UNINSTALLTARGET += ;rm -f /bin/FFT
CLEANTARGET := rm -f FFT
endif
all: $(ALLTARGET)
FFT.app: FFT
	mkdir FFT.app
	mkdir FFT.app/Contents
	mkdir FFT.app/Contents/MacOS
	mkdir FFT.app/Contents/Resources
	cp resource/Info.plist FFT.app/Contents/
	echo -n 'APPL????' > FFT.app/Contents/PkgInfo
	mv FFT FFT.app/Contents/MacOS/FFT
	cp resource/FFT.icns FFT.app/Contents/Resources/
FFT:
	$(CC) -o FFT src/main.cpp src/main.h src/fft.cpp src/fft.h src/wxlibs.h
install:
	$(INSTALLTARGET)
uninstall:
	$(UNINSTALLTARGET)
clean:
	$(CLEANTARGET)