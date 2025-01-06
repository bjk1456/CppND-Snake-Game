#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "garter.h"

class Controller {
 public:
  void HandleInput(bool &running, Garter &garter) const;

 private:
  void ChangeDirection(Garter &garter, Garter::Direction input,
                       Garter::Direction opposite) const;
};

#endif