#ifndef TIMELABEL_H
#define TIMELABEL_H

#include <godot_cpp/classes/label.hpp>

namespace godot {

class TimeLabel : public Label {
	GDCLASS(TimeLabel, Label)

private:
	double time_passed;

protected:
	static void _bind_methods();

public:
	TimeLabel();
	~TimeLabel();

	void _process(double delta) override;

    void show_time();
};

}

#endif