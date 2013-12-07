#ifndef __MARLIN_EJECT_H
#define __MARLIN_EJECT_H

struct axis_state {
    float min;
    float max;
};

extern struct axis_state xtrack;

void track_axis(struct axis_state *axis_state, float pos);
void reset_axis(struct axis_state *axis_state);
void center_x_on_track(struct axis_state *axis_state);
float get_axis_center(struct axis_state *axis_state);

#endif /* __MARLIN_EJECT_H */
