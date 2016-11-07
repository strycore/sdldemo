NAME = sdldemo
O    = o
RM   = rm -f
CXX  = g++
PROG = sdldemo

DEFAULT_CFLAGS = `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -L. -lGLU -lGL
MORE_CFLAGS = -O2 -Wall

CPPFLAGS = $(DEFAULT_CFLAGS) $(MORE_CFLAGS) -DLINUX

OBJS = $(NAME).$(O)

$(PROG): $(OBJS)
	$(CXX) $(CPPFLAGS) -o $(PROG) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(PROG) *.$(O)
