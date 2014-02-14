/**
 *  This file is a part of ncxmms2, an XMMS2 Client.
 *
 *  Copyright (C) 2011-2014 Pavel Kunavin <tusk.kun@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../lib/window.h"

namespace Xmms {
class Client;
}

namespace ncxmms2 {

class HeaderWindow;
class StackedWindow;
class StatusArea;

class MainWindow : public Window
{
public:
    MainWindow(Xmms::Client *xmmsClient);
    ~MainWindow();

    enum StackedWindows
    {
        StackedHelpBrowser,
        StackedPlaylistWindow,
        StackedLocalFileBrowserWindow,
        StackedMedialibBrowser,
        StackedPlaylistsBrowser,
        StackedEqualizerWindow
    };

    virtual void keyPressedEvent(const KeyEvent& keyEvent);
    virtual void mouseEvent(const MouseEvent& ev);

protected:
    virtual void resizeChildren(const Size& size);

private:
    HeaderWindow *m_headerWindow;
    StackedWindow *m_stackedWindow;
    StatusArea *m_statusArea;
    Xmms::Client *m_xmmsClient;

    void setVisibleWindow(StackedWindows win);
    void handleStackedWindowNameChanged(StackedWindows win, const std::string& title);
};
} // ncxmms2


#endif // MAINWINDOW_H
