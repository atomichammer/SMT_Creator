#include "chipb.h"

ChipB::ChipB() : QMimeData()
{
    mime_formats.clear();
    mime_formats.append("smtconverter/chip");
}

QStringList ChipB::formats() const
{
    return mime_formats;
}

QVariant ChipB::retrieveData(const QString &format, QVariant::Type preferredType) const
{
    Q_UNUSED(preferredType);
    if(format == "smtconverter/chip")
    {
        QVariant v;
        v.setValue(data);
        return v;
    }
    return 0;
}
