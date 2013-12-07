#include "Marlin.h"

extern "C" {
#include "eject.h"

/* WHYYYYYYYYYYYYYYYYYYYY */
extern float destination[NUM_AXIS];

struct axis_state xtrack = {
    .min = 200.0f,
    .max = 0.0f,
};

void track_axis(struct axis_state *axis_state, float pos)
{
    if (pos > axis_state->max)
        axis_state->max = pos;

    if (pos < axis_state->min)
        axis_state->min = pos;
}

void reset_axis(struct axis_state *axis_state)
{
    axis_state->max = 0.0f;
    axis_state->min = 200.0f;
}

float get_axis_center(struct axis_state *axis_state)
{
    return (axis_state->max + axis_state->min)/2.0;
}

void center_x_on_track(struct axis_state *axis_state)
{
    float center;

    center = (axis_state->max + axis_state->min)/2.0;

    /*
     * I hope this horseshit is right..
     * Fucking global state for everything goddamnit
     */
    destination[X_AXIS] = center;
    destination[Y_AXIS] = current_position[Y_AXIS];
    destination[Z_AXIS] = current_position[Z_AXIS];
    destination[E_AXIS] = current_position[E_AXIS];
    prepare_move();
}

};
