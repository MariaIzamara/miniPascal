#include "./CaseOption.h"

CaseOption::CaseOption(Type* value, Command* cmd)
  : m_value(value), m_cmd(cmd) {
};

CaseOption::~CaseOption() {
  delete m_value;
};
