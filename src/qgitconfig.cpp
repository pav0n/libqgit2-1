/******************************************************************************
 * This file is part of the libqgit2 library
 * Copyright (c) 2012 Laszlo Papp <djszapi@archlinux.us>
 * Copyright (C) 2013 Leonardo Giordani
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "qgitconfig.h"

#include <QtCore/QDir>
#include <QtCore/QFile>

#include <src/qgitexception.h>
#include <src/qgitrepository.h>

namespace LibQGit2
{

Config::Config(git_config *cfg)
    : d(cfg)
{
    if (d == 0)
        git_config_new(&d);
}

Config::Config(const Config &other)
    : d(other.d)
{
}

Config::~Config()
{
    git_config_free(d);
}

Config Config::fromGlobalConfig()
{
    git_config * def;
    git_config * cfg;
    git_config_open_default(&def);
    if ( git_config_open_global(&cfg, def) == GIT_OK )
        return Config(cfg);

    return Config();
}

QString Config::findGlobal()
{
    char buffer[GIT_PATH_MAX];
    qGitThrow( git_config_find_global(buffer, GIT_PATH_MAX) );

    return QFile::decodeName(buffer);
}

QString Config::findSystem()
{
    char buffer[GIT_PATH_MAX];
    qGitThrow( git_config_find_system(buffer, GIT_PATH_MAX) );

    return QFile::decodeName(buffer);
}

bool Config::append(const QString &path, git_config_level_t level, int force)
{
    return GIT_OK == git_config_add_file_ondisk(d, QFile::encodeName(path).constData(), level, force);
}

QVariant Config::value(const QString &key, const QVariant &defaultValue) const
{
    const char * result = 0;
    if (git_config_get_string(&result, d, key.toUtf8().constData()) == GIT_OK)
        return QString::fromUtf8(result);

    return defaultValue;
}

void Config::setValue(const QString &key, const QVariant &value)
{
    qGitThrow( git_config_set_string(d, key.toUtf8(), value.toString().toUtf8().constData()) );
}


} // LibQGit2

