#include "ProcessManager.hpp"
#include "Process.hpp"
#include <algorithm>

ProcessManager::ProcessManager() { };
ProcessManager::~ProcessManager() { };

void ProcessManager::update(float &deltaTime) {
    // TODO: add error checking
    for (auto itr=m_procs.begin(); itr != m_procs.end(); itr++) {
        if ((*itr)->state() == Process::UNINITIALIZED) (*itr)->init();
        if ((*itr)->state() == Process::RUNNING)       (*itr)->update(deltaTime);
        if ((*itr)->isDead()) {
            if ((*itr)->state() == Process::SUCCESS) {
                (*itr)->postSuccess();
                if ((*itr)->hasChild()) attachProcess((*itr)->getChild());
            }
            if ((*itr)->state() == Process::FAILED)  (*itr)->postFailed();
            if ((*itr)->state() == Process::ABORTED) (*itr)->postAborted();
            removeProcess(*itr);
        }
    }
}

void ProcessManager::removeProcess(Process *p) {
    for (auto itr=m_procs.begin(); itr != m_procs.end(); itr++) {
        if (*itr == p) {
            m_procs.erase(itr);
            break;
        }
    }
}

void ProcessManager::attachProcess(Process *p) {
    // if not in list of processes, add it
    if (std::find(m_procs.begin(), m_procs.end(), p) == m_procs.end()) {
        p->setID(m_procs.size());
        m_procs.push_back(p);
    }
}

void ProcessManager::abortAll() {
    // set state of all processes to ABORTED
    for (auto itr=m_procs.begin(); itr != m_procs.end(); itr++) {
        (*itr)->setState(Process::ABORTED);
    }
}

