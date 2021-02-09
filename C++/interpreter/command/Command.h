#ifndef COMMAND_H
#define COMMAND_H

class Command {
	public:
		int line() const { return m_line; }
		virtual void execute() = 0;

	protected:
		Command(int line) : m_line(line) {}
		virtual ~Command() {}

	private:
		int m_line;
};

#endif
