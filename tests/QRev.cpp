// A try to port libgit2 status.c example to libqgit2

#include <QCoreApplication>
#include <QTimer>
#include <iostream>

#include <bitset>

#include "qgitcommit.h"
#include "qgitrepository.h"
#include "qgitrevwalk.h"

#include "QRev.h"

using namespace LibQGit2;

QRev::QRev()
{
    // Create a new repository object
    Repository * repo = new LibQGit2::Repository();
    
    // Open a local fixed path
    repo->open(QString("/home/leo/projects/libqgit2"));
    
    RevWalk * rw = new RevWalk(*repo);
    
    rw->setSorting(RevWalk::Topological);
    
    rw->pushHead();

    Commit commit;
    while(rw->next(commit)) {
        QByteArray qb = commit.oid().format();
        std::cout << qb.data() << std::endl;
    }
    
}

QRev::~QRev()
{}

#include "QRev.moc"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    QRev foo;
    return app.exec();
}

