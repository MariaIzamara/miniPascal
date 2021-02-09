#ifndef BLOCKCOMMAND_H
#define BLOCKCOMMAND_H

class BlocksCommand {
public:
    virtual ~BlocksCommand() {}

    virtual void execute() = 0;
	// virtual void addCommand(cmd Command) = 0

protected:
    explicit BlocksCommand(int line) : m_line(line) {}

private:
    int m_line;

};

#endif
