#ifndef DESIGNUI_H
#define DESIGNUI_H

#include <QtWidgets>

//该文件用于各种ui设计


// 瀑布流布局类
class WaterfallLayout : public QLayout {
public:
    explicit WaterfallLayout(QWidget *parent = nullptr, int margin = 0, int spacing = -1)
        : QLayout(parent), m_columnCount(3), m_spacing(spacing) {
        setContentsMargins(margin, margin, margin, margin);
    }

    ~WaterfallLayout() override {
        QLayoutItem *item;
        while ((item = takeAt(0)))
            delete item;
    }

    void addItem(QLayoutItem *item) override {
        m_items.append(item);
        updateLayout();
    }

    void setColumnCount(int count) {
        if (count > 0 && m_columnCount != count) {
            m_columnCount = count;
            updateLayout();
        }
    }

    QLayoutItem *itemAt(int index) const override {
        return m_items.value(index);
    }

    QLayoutItem *takeAt(int index) override {
        if (index >= 0 && index < m_items.size())
            return m_items.takeAt(index);
        return nullptr;
    }

    int count() const override {
        return m_items.size();
    }

    QSize sizeHint() const override {
        return minimumSize();
    }

    QSize minimumSize() const override {
        QSize size;
        for (const auto &item : m_items)
            size = size.expandedTo(item->minimumSize());

        const QMargins margins = contentsMargins();
        size += QSize(margins.left() + margins.right(), margins.top() + margins.bottom());
        return size;
    }

    void setGeometry(const QRect &rect) override {
        QLayout::setGeometry(rect);
        updateLayout();
    }


    void updateLayout() {
        if (m_items.isEmpty() || !parent()) return;

        const QRect &rect = parentWidget()->contentsRect();
        if (rect.isEmpty()) return;

        const QMargins margins = contentsMargins();
        QRect effectiveRect = rect.adjusted(margins.left(), margins.top(),
                                            -margins.right(), -margins.bottom());

        int idealColumnWidth = 240;
        int columnCount = qMax(1, effectiveRect.width() / idealColumnWidth);

        if (columnCount != m_columnCount) {
            m_columnCount = columnCount;
        }

        int columnWidth = (effectiveRect.width() - (m_columnCount - 1) * spacing()) / m_columnCount;

        QVector<int> columnHeights(m_columnCount, 0);

        for (int i = 0; i < m_items.size(); ++i) {
            int minHeightColumn = 0;
            for (int j = 1; j < m_columnCount; ++j) {
                if (columnHeights[j] < columnHeights[minHeightColumn])
                    minHeightColumn = j;
            }

            int x = effectiveRect.x() + minHeightColumn * (columnWidth + spacing());
            int y = effectiveRect.y() + columnHeights[minHeightColumn];

            QLayoutItem *item = m_items[i];
            QSize itemSize = item->sizeHint();
            double aspectRatio = (double)itemSize.width() / itemSize.height();
            int itemHeight = columnWidth / aspectRatio;
            item->setGeometry(QRect(x, y, columnWidth, itemHeight));

            columnHeights[minHeightColumn] += itemHeight + spacing();
        }
    }


    QList<QLayoutItem*> m_items;
    int m_columnCount;
    int m_spacing;
};

#endif // DESIGNUI_H
