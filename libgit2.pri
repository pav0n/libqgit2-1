SOURCES += \
    attr.c \
    attr_file.c \
    blob.c \
    buffer.c \
    cache.c \
    commit.c \
    config.c \
    config_file.c \
    delta-apply.c \
    errors.c \
    fetch.c \
    filebuf.c \
    fileops.c \
    global.c \
    hash.c \
    ignore.c \
    index.c \
    indexer.c \
    mwindow.c \
    netops.c \
    object.c \
    odb.c \
    odb_loose.c \
    odb_pack.c \
    oid.c \
    pack.c \
    path.c \
    pkt.c \
    posix.c \
    pqueue.c \
    protocol.c \
    reflog.c \
    refs.c \
    refspec.c \
    remote.c \
    repository.c \
    revwalk.c \
    sha1.c \
    sha1_lookup.c \
    signature.c \
    status.c \
    tag.c \
    thread-utils.c \
    transport.c \
    tree-cache.c \
    tree.c \
    tsort.c \
    util.c \
    vector.c

unix:SOURCES += \
    unix/map.c

win32:SOURCES += \
    win32/dir.c \
    win32/fnmatch.c \
    win32/map.c \
    win32/posix_w32.c \
    win32/pthread.c \
    win32/utf-conv.c

win32:OTHER_FILES += git2.rc
