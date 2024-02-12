#include "bouncingBall.h"
#include "AnimationWindow.h"
#include "std_lib_facilities.h"

constexpr Point BOUNCE_WINDOW_TOP_LEFT{50, 50};
constexpr int BOUNCE_WINDOW_WIDTH{800};
constexpr int BOUNCE_WINDOW_HEIGHT{500};

void bouncing_ball() {
    AnimationWindow window{BOUNCE_WINDOW_TOP_LEFT.x, BOUNCE_WINDOW_TOP_LEFT.y,
                           BOUNCE_WINDOW_WIDTH, BOUNCE_WINDOW_HEIGHT,
                           "Bouncing ball"};

    const int radius{30};
    int alpha{1};
    int velocity{2};
    Color colour_up{Color::blue};
    Color colour_down{Color::blue};
    int x{0};
    int y{360};
    int increment_x{0};
    int increment_y{0};
    int count_bounce_top{0};
    int count_bounce_bottom{0};
    int count_num_passes{0};

    std::map<int, Color> COLORS{{1, Color::blue},
                                {2, Color::red},
                                {3, Color::yellow},
                                {4, Color::pink}};

    // read from configuration file
    std::filesystem::path config_file{"konfigurasjon.txt"};
    std::ifstream is{config_file};

    if (!is) {
        std::cout << "Filen ble ikke åpnet.";
        return;
    }

    Config slow_conf;
    is >> slow_conf;
    Config fast_conf;
    is >> fast_conf;

    Config conf = slow_conf;

    colour_up = COLORS.at(conf.up_color);
    colour_down = COLORS.at(conf.down_color);
    velocity = conf.vel_abs;

    // initialise the run

    while (!window.should_close()) {
        // determine increments based on the velocity
        increment_x = velocity * cos(alpha);
        increment_y = velocity * sin(alpha);

        // movement i x-direction
        if ((increment_x + x) > window.width()) {
            // reached right side - wrap around to the leftmost
            x = 0;
            // increment counter which counts number of full left-to-right
            // passes
            count_num_passes++;
            // alternate between slow and fast configuration every fifth pass
            if (count_num_passes % 2 == 0) {
                if (conf.vel_abs == slow_conf.vel_abs) {
                    conf = fast_conf;
                } else {
                    conf = slow_conf;
                }
                colour_up = COLORS.at(conf.up_color);
                colour_down = COLORS.at(conf.down_color);
                velocity = conf.vel_abs;
            }
        } else {
            // moving rightwards
            x += increment_x;
        }

        // movement i y-direction
        if (y <= 0) {
            count_bounce_top++;
        } else if (y >= window.height()) {
            count_bounce_bottom++;
        }

        if (((count_bounce_top + count_bounce_bottom) % 2) == 0) {
            y -= increment_y;
            window.draw_circle(Point{x, y}, 30, colour_up);
        } else {
            y += increment_y;
            window.draw_circle(Point{x, y}, 30, colour_down);
        }

        window.next_frame();
    }
}

istream &operator>>(istream &is, Config &cfg) {
    int up_color, down_color, vel_abs;
    is >> up_color;
    is >> down_color;
    is >> vel_abs;
    cfg.down_color = down_color;
    cfg.up_color = up_color;
    cfg.vel_abs = vel_abs;
    return is;
}
